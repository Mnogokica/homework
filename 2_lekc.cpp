#include <cstdlib>
#include <iostream>
using namespace std;
//M.D. lasiit prezentaciju, uzrakstiit programmu, kas nodefinee 5 mainiigos, pieskir veertiibas un izpilda darbiibas
//programma, kas prasa ievadiit 2 mainiigos (int) un veic + - * /, izvada rezultaatus
int main(){
int x=11, y=3;
float b=0.5;
double a=12.35;
char c='!', c1='A';
string s="Pixel kotik meow";
cout<<"Summa: "<<x+y;
cout<<"\n"<<x<<" + "<<y<<" = "<<x+y;
cout<<"\n"<<x<<" - "<<y<<" = "<<x-y;
cout<<"\n"<<x<<" * "<<y<<" = "<<x*y;
cout<<"\n"<<x<<" / "<<y<<" = "<<float(x)/y;
cout<<"\nIzmeers INT: "<<sizeof(int)<<" baiti";
cout<<"\nFloat un double summa: "<<b+a;
cout<<"\nIzmeers float: "<<sizeof(float)<<" baiti";
cout<<"\nIzmeers double: "<<sizeof(double)<<" baiti";
cout<<"\n"<<c<<" un "<<c1;
cout<<"\nIzmeers char: "<<sizeof(char)<<" baits";
cout<<endl<<s;
cout<<endl<<int(c1);//simbola kods 67
cout<<endl<<int('a');//simbola kods 97
cout<<endl<<int('r');//simbola kods 114
cout<<endl<<char('a'-32);//A
cout<<"\nIzmeers string: "<<sizeof(string)<<" baiti";
  system("pause>nul");
  return 0;
}
