/*****************************************************
copyright (C), 2014-2015, Lighting Studio. Co.,     Ltd. 
File name：
Author：Jerey_Jobs    Version:0.1    Date: 
Description：
Funcion List: 
*****************************************************/

#include <stdio.h>

#define MAX 100

enum stack{NUM_EMPTY = -111,SYMBOL_EMPTY,NOT_EMPTY,FULL};

int num[MAX];          //操作数栈
char symbol[MAX];      //运算符栈
int top_n;             //操作数栈顶指针
int top_s;             //操作符栈顶指针


/*初始化操作数栈和运算符栈*/
void init_stack()
{
    top_n = -1;
    top_s = -1;
}

/*操作数压栈*/
void push_num_stack(int number)
{
    if(top_n == MAX -1)             //判断是否栈满
    {
        return FULL;
    }
    top_n++;
    num[top_n] = number;
}

/*判断操作数栈是否为空*/
int is_num_empty()
{
    if(top_n == -1)                  //栈顶指针为-1即为空栈
    {
        return NUM_EMPTY;
    }

    return NOT_EMPTY;
}

/*操作数出栈*/
int pop_num_stack()
{
    if(is_num_empty() != NUM_EMPTY)   //出栈先判断是否为空
    {
        return num[top_n--];
    }

    return NUM_EMPTY;
}

/*运算符入栈*/
void push_symbol_stack(char p)
{
    if(top_s == MAX - 1)              //判断是否栈满
    {
        return FULL;
    }
    top_s++;
    symbol[top_s] = p;
}

/*运算符出栈*/
char pop_symbol_stack()
{
    if(top_s == -1)                    //运算符栈是否为空
    {
        return SYMBOL_EMPTY;
    }
   
    return symbol[top_s--];   
}

/*判断运算符优先级*/
int pri(char c)
{
    switch(c)
    {
        case '+':return 1;break;
        case '-':return -1;break;
        case '*':return 2;break;
        case '/':return -2;break;
    }
}

/*读取str并返回计算结果*/
int calculate(char *str)
{
    int result;                   //结果
    char *tmp = str;              
    int flag1;                    //临时后操作数
    int flag2;                    //临时前操作数
    char tmp_tops;                //临时运算符

    /*遍历字符串*/
    while(*tmp != '\0')
    {
        /*若为数字压入操作数栈，若不是则为运算符*/
        if((*tmp <= '9') && (*tmp) >= '0')
        {
            push_num_stack(*tmp - '0');
        }
        else
	{
	    /*若是运算符则判断运算符栈是否为空，若为空 直接压栈*/
	    if(top_s == -1)
	    {
	        push_symbol_stack(*tmp);
	    }
	    else 
	    {
	        /*不为空 则判断优先级是否高于栈顶 若高于则压栈*/
	        if(abs(pri(*tmp)) > abs(pri(symbol[top_s])))
		{
		    push_symbol_stack(*tmp);
		}
		else
		{
		    /*取出操作数栈顶2元素和一个操作符进行运算*/   
		    flag2 = pop_num_stack();          
		    flag1 = pop_num_stack();
                    tmp_tops = pop_symbol_stack();

                    if(pri(tmp_tops) == 1)
		    {
		        result = flag1 + flag2;
		    }
		    else if(pri(tmp_tops) == -1)
		    {
		        result = flag1 - flag2;
		    }

		    else if(pri(tmp_tops) == 2)
		    {
		        result = flag1 * flag2;
		    }
		    else if(pri(tmp_tops) == -2)
		    {
		        result = flag1 / flag2;
		    }
		    
		    push_num_stack(result);
		    push_symbol_stack(*tmp);
                    
		}
	    }
	}
  
        tmp++;
    }

    while(top_s != -1)
    {
    
        flag2 = pop_num_stack();
        flag1 = pop_num_stack();
        tmp_tops = pop_symbol_stack();

        if(pri(tmp_tops) == 1)
        {
            result = flag1 + flag2;
        }
        else if(pri(tmp_tops) == -1)
        {
            result = flag1 - flag2;
        }

        else if(pri(tmp_tops) == 2)
        {
            result = flag1 * flag2;
        }
        else if(pri(tmp_tops) == -2)
        {
            result = flag1 / flag2;
        }
    
        push_num_stack(result);

        }

    return result;
}

int main()
{
    char str[MAX];
    int result;

    printf("please input : ");
    scanf("%s",str);

    init_stack();

    result = calculate(str);

    printf("the result is : %d\n",result);

    return 0;
}
