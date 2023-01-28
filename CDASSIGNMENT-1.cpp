#include<iostream>
using namespace std;
#include<fstream>
#include<string>
#include<string.h>
#include<list>
#include<map>
map<string,string>map2;
int n,l=0;
string tp,NT[20],R[20],T[20];
bool search(string,string*);
struct X{
string first[10];
int length;
string follow[10];
int  flength;
}p[20];
struct MYSTRUCT {
string NT;
int start;
int length;
}Tp[10];

bool  searchFirst(string value, struct X array[],int index)
{
    int size = array[index].length;
    for (int i = 0; i <= size; i++)
    {
        if (value == array[index].first[i])
        {
            return true;
        }
    }

    return false;
}
bool  searchFollow(string value, struct X array[],int index)
{
    int size = array[index].flength;
    for (int i = 0; i <= size; i++)
    {
        if (value == array[index].follow[i])
        {
            return true;
        }
    }

    return false;
}


int  search(string value, struct MYSTRUCT array[])
{
    int size = sizeof(array);
    for (int i = 0; i <= size; i++)
    {
        if (value == array[i].NT)
        {
            return i;
        }
    }

    return -1;
}
bool  searchTerm(string value, string  array[])
{
    int size = sizeof(array);
    for (int i = 0; i <= size; i++)
    {
        if (value == array[i])
        {
            return true;
        }
    }

    return false;
}
int production(int i){
 for(int j=0;j<=n;j++)
{
if(i>=Tp[j].start  && i<(Tp[j].start+Tp[j].length))
 return j;
}
}

void First()
{
for(int i=n;i>=0;i--)
{
for(int j=Tp[i].start;j<Tp[i].start+Tp[i].length;j++)
{string q;
 q=R[j][0];
bool ps=searchTerm(q,T);
if(ps==true)
{
bool v=searchFirst(q,p,i);
if(v==false){
p[i].first[p[i].length]=q;
p[i].length++;
}
}
else
{
int t=search(q,Tp);
int h=0;
bool n;
int u=p[i].length;
for(int l=p[i].length;l<u+p[t].length;l++)
{
n=searchFirst(p[t].first[h],p,i);
if(n==false){
p[i].first[l]=p[t].first[h];
h++;
p[i].length++;
}
}

}
}
}
}
void follow()
{
p[0].follow[0]="$";
p[0].flength++;
for(int y=0;y<=n;y++){
 for(int i=0;i<=n;i++)
{
string  z=Tp[i].NT;

char s=z[0];
for(int j=0;j<=l;j++){
for(int k=0;k<R[j].length();k++)
{char e=R[j][k];
 if(s==e)
{
int h=k+1;
string w;
if(h==R[j].length())
{
int d=production(j);
for(int u=0;u<p[d].flength;u++)
{int x=p[i].flength;
bool n=searchFollow(p[d].follow[u],p,i);
if(n==false){
p[i].follow[x]=p[d].follow[u];
p[i].flength++;
}
}
}


w=R[j][h];

bool f=searchTerm(w,T);
int x=p[i].flength;
if(f==false)
{
int r=search(w,Tp);

for(int u=0;u<p[r].length;u++)
{int x=p[i].flength;
bool n=searchFollow(p[r].first[u],p,i);
if(n==false){
p[i].follow[x]=p[r].first[u];
p[i].flength++;
}
}
}
else
{
bool n=searchFollow(w,p,i);
if(n==false){
p[i].follow[x]=w;
p[i].flength++;
}
}
}
}
}
}
}
}



int main(int argc ,char * argv[])
{
int lp,i;
        ifstream my_file;
        my_file.open(argv[1]);
        if(!my_file)
        cout<<"file not found";
        else{
        char tp1[100];
        const char *left,*x;
        const char *right;
        cout<<"file found\n";
        int j=0,d=0;
        while(getline(my_file,tp)){
        strcpy(tp1,tp.c_str());
        left=strtok(tp1,"-");
        right=strtok(NULL," ");
        if(left!=NULL){
        int u=search(left,Tp);
if(u==-1)
{
Tp[i].NT=left;
if(i==0)
{
Tp[i].start=0;
Tp[i].length=1;
}
else
Tp[i].start=Tp[i-1].length+Tp[i-1].start;
n=i;
i++;
Tp[i].length=1;
}
else
{
Tp[u].length++;
}
}
if(right!=NULL){
        R[j]=right;
lp=j;
j++;
}
}
for( i=0;i<=lp;i++)
{int j=0;
 while(j<R[i].length())
{
bool q;
int k;
string c;
 c=R[i][j];
k=search(c,Tp);
q=searchTerm(c,T);
//if(c!="@"){
if(k==-1 && q==false)
{if(c!="@")
T[l]=c;

l++;}
//}
j++;
}
}
}
cout<<"the terminals are\n";
for( i=0;i<=l;i++)
cout<<T[i];
cout<<"\n";
for( i=0;i<=n;i++)
{
cout<<Tp[i].NT<<"       "<<Tp[i].start<<"       "<<Tp[i].length<<"\n";
}
First();
follow();
for( i=0;i<=n;i++)
{
cout<<"first of "<<Tp[i].NT;
 for(int j=0;j<=p[i].length;j++)
{
 cout<<p[i].first[j]<<" ";
}
cout<<"\n";
}
for(i=0;i<=n;i++)
{
cout<<"follow of "<<Tp[i].NT;
 for(int j=0;j<=p[i].flength;j++)
{
 cout<<p[i].follow[j]<<" ";
}

cout<<"\n";
}
T[l+1]="$";
cout<<"	";
for(int i=0;i<=l+1;i++)
{
 cout<<T[i]<<"	";
}
cout<<"\n";
for(int i=0;i<=n;i++)
{
cout<<Tp[i].NT;
cout<<"	";
for(int j=0;j<=l+1;j++)
{ 
for(int k=Tp[i].start;k<Tp[i].start+Tp[i].length;k++)
{
string c;
c=R[k][0];
int o=search(c,Tp);
//int o=search(c,Tp);
//cout<<"j value"<<j<<"\n";
int u=production(i);
//cout<<"i value"<<i<<"\n";
//cout<<"production no"<<o<<"\n";
 if(c=="@")
{
//cout<<"entered"<<"\n";
//cout<<"i value"<<i<<"\n";
//cout<<"production no"<<u<<"\n";
 for(int f=0;f<p[i].flength;f++)
{ //cout<<"follow of"<<p[i].follow[f]<<"\n";
  //cout<<"terminal ="<<T[j]<<"\n";
  if(p[i].follow[f]==T[j])
  cout<<k+1;
}
}

else if(o==-1){
 if(T[j]==c)
 cout<<k+1;
}
else{
  for(int f=0;f<p[n].length;f++)
{
  if(p[o].first[f]==T[j])
  cout<<k+1;
}

}
}
cout<<"	";
}
cout<<"\n";
}
return 0;
}

