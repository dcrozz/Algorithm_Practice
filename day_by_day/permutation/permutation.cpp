#include "iostream" 
#include "algorithm" 
using namespace std;
 void permutation(char* str,int length) {  sort(str,str+length);
  do  {   for(int i=0;i<length;i++)    cout<<str[i];
   cout<<endl;
  }while(next_permutation(str,str+length));
 } int main(void) {  char str[] = "acb";
  cout<<str<<"所有全排列的结果为："<<endl;
  permutation(str,3);
  system("pause");
  return 0;
 }
