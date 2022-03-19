//尝试第一次上传文件
//  main.c
//  firstC_20210115
//  Created by MacBook on 2021/1/29.
//  查找1-输入的数字中所有的质数




#include <stdio.h>
#include <string.h>

void find_zhishu(int num){
       if(num ==1 || num==2 || num ==3) {printf("%d ",num); return; }
       for(int i=2;i<=num/2;i++){
       if(num%i !=0) continue; //这个地方必须用continue 如果用break是错误的
	else return;
}
       printf("%d \n",num);
}





int main()
{  
   int num;
   printf("请输入一个数字");
   scanf("%d",&num);
   for(int j=1;j<=num;j++){
     find_zhishu(j);
   }
}



