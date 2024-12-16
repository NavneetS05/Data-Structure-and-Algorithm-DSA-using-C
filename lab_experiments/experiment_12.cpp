
#include<stdio.h>
int main(){
  int arr[] = { 3 , 0 , 1 };
  int n = 4;
  int ans = 0;
  for(int i=0;i<=n;i++){
      ans = ans^i;
  }
  for(int i = 0 ; i<n;i++){
      ans = ans ^ arr[i];
  }
  printf("%d",ans);
  return 0;
}
