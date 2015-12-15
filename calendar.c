#include <stdio.h>

//返回天数函数 
int days(int year,int month) 
{
    int m[]={31,28,31,30,31,30,31,31,30,31,30,31};
    //判断是否闰年
    if((year%4==0&&year%100!=0)||year%400==0)
    				m[1]=29;
    return(m[month-1]);
}
//打印月份中的第一天是星期几
int CaculateWeekDay(int year,int month)
{
	int day;
	day = 1;
	if(month==1||month==2) 
	{
		month+=12;
		year--;
	}
	int iWeek=(day+2*month+3*(month+1)/5+year+year/4-year/100+year/400)%7;
	switch(iWeek)
	{
		case 0: return 1; break;
		case 1: return 2; break;
		case 2: return 3; break;
		case 3: return 4; break;
		case 4: return 5; break;
		case 5: return 6; break;
		case 6: return 7; break;
	}
}
//打印月份中每一天
void print_day(int year,int month,int pos)
{
	int _days;
	int i;
	int num1 = 0;
	int num2 = 0;
	_days = days(year,month);
	int date[_days];
	for(i = 0;i < _days;i++)
	{
		date[i] = i + 1;
		num1 ++;
		num2 ++;
		printf("%d\t",date[i] );
		if(num1 == 7 - pos + 1 || num2 % 7 == 0 )
		{
			printf("\n");

			num2 = 0;
		}
		
		// if(date[i - 7] - date[i] == 7)
		// {
		// 	printf("\n");
		// }

	}

}
//打印月份
void print_month(int year,int month)
{
	int _week;
	
	_week = CaculateWeekDay(year,month);
	// printf("每个月的第一天%d\n",_week );
	switch (_week)
	{
		case 1 :
				print_day(year,1,1);
				break;
		case 2 :
				printf("  \t");
				print_day(year,month,2);
				break;
		case 3 :
				printf("  \t  \t");
				print_day(year,month,3);
				break;
		case 4 :
				printf("  \t  \t  \t");
				print_day(year,month,4);				
				break;
		case 5 :
				printf("  \t  \t  \t  \t");
				print_day(year,month,5);			
				break;
		case 6 :
				printf("  \t  \t  \t  \t  \t");
				print_day(year,month,6);			
				break;
		case 7 :
				printf("  \t  \t  \t  \t  \t  \t");
				print_day(year,month,7);				
				break;

	}

}
//打印日历月头
void print_head(int year,int month)
{
		printf("%d 年 0%d 月\n",year,month);
		printf("一\t二\t三\t四\t五\t六\t日\t\n");
}

int main(int argc, char const *argv[])
{
	int year;
	int i;

	printf("万年历\n");

	scanf("%d",&year);

	for(i = 1;i <= 12;i++)
	{
		printf("\n");
		print_head(year,i);

		print_month(year,i);
	}

	printf("\n");
	return 0;
}