// PAIRSUM

#include<stdio.h>

int main(){
int input,i,j,count=0,k=0,max,l,m,count1=0;
scanf("%d",&input);
if(input>=4){
int a[input],b[input][input];
for(i=0;i<input;i++)
scanf("%d",&a[i]);
for(i=0;i<input;i++){
for(j=i+1;j<input;j++)
{b[i][j]=a[i]+a[j];
count++;}}
int c[2*count],d[2*count];
k=0;
for(i=0;i<input;i++)
for(j=i+1;j<input;j++){
c[k]=b[i][j];
k++;}
k=0;l=0;count1=0;
while(l<count){
if(c[l]!=0){
d[k]=c[l];
for(i=l;i<count;i++){
if(d[k]==c[i]){
c[i]=0;
count1++;}}}
d[k+1]=count1;
count1=0;
k+=2;
l++;}
max=d[1];
for(i=3;i<(2*count);i+=2){
if(max<d[i])
max=d[i];}
printf("%d\n",2*max);}
return 0;
}
