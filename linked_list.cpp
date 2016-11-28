#include<iostream>
using namespace std;
class Node{
public:
int data;
Node *next;
Node(int a){
this->data=a;
this->next=NULL;
}
int get_data(){
return this->data;
}
void set_data(int data){
this->data=data;
}
void set_next(Node *next){
this->next=next;
}
Node* get_next(){
return this->next;
}
static Node* Create_newnode(int a){
Node *newnode;
newnode=new Node(a);
return newnode;
}
};
class Linklist{
public:
Node *head;
Node *last;
void set_last(Node * ptr){
this->last=ptr;
}
Node* get_last(){
return this->last;
}
void set_head(Node *ptr){
this->head=ptr;
}
Node* get_head(){
return this->head;
}
void add_node(int a){
Node *newnode=Node::Create_newnode(a);
if(get_head()==NULL){
set_head(newnode);
}
if(get_last()!=NULL){
last->set_next(newnode);
}
set_last(newnode);
}
void clear(){
set_head(NULL);
set_last(NULL);
}
int equal(Linklist l1){
Node *ptr1=get_head();
Node *ptr2=l1.get_head();
int flag=1;
while(ptr1!=NULL||ptr2!=NULL){
if(ptr1->get_data()!=ptr2->get_data()){
flag=0;
break;
}
ptr1=ptr1->get_next();
ptr2=ptr2->get_next();
}
return flag;
}
int get(int index){
Node *ptr1=get_head();
while(ptr1!=NULL){
index--;
if(index==0){
return ptr1->get_data();
}
ptr1=ptr1->get_next();
}
return 0;
}
void insert(int index,int value){
Node *newnode=Node::Create_newnode(value);
Node *ptr1=get_head();
while(ptr1!=NULL){
if(index--){
break;
}
ptr1=ptr1->get_next();
}
if(ptr1==get_head()){
newnode->set_next(get_head());
set_head(newnode);
}
else{
if(ptr1==get_last()){
last->set_next(newnode);
set_last(newnode);
}
else{
newnode->set_next(ptr1->get_next());
ptr1->set_next(newnode);
}
}
}
int isempty(){
if(get_head()==NULL)
return 1;
else
return 0;
}
void remove(int index){
index--;
Node *ptr1=get_head();
while(ptr1!=NULL){
if(index--)
break;
ptr1=ptr1->get_next();
}
if(ptr1==get_head()){
set_head(ptr1=ptr1->get_next());
}
else{
if(ptr1==get_last()){
while(ptr1!=get_last()){
ptr1=ptr1->get_next();
}
set_last(ptr1);
ptr1->set_next(NULL);
}
else{
ptr1->set_next(ptr1->get_next()->get_next());
}
}
}
void set(int index,int value){
index--;
Node *ptr1=get_head();
while(ptr1!=NULL){
if(index--)
break;
ptr1=ptr1->get_next();
}
ptr1->set_data(value);
}
int size(){
int index=0;
Node *ptr1=get_head();
while(ptr1!=NULL){
index++;
ptr1=ptr1->get_next();
}
return index; 
}
Linklist subList(int start,int length){
start--;
Node *ptr1=get_head();
while(ptr1!=NULL){
if(start--)
break;
ptr1=ptr1->get_next();
}
Linklist l1;
l1.set_head(ptr1);
while(ptr1!=NULL){
if(length--)
break;
ptr1=ptr1->get_next();
}
l1.set_last(ptr1);
return l1;
}
char* toString(){
int a=size();
int b,c,sum=0;
char *s=new char[a];
Node *ptr1=get_head();
a=0;
while(ptr1!=NULL){
if(ptr1->get_data()<=9){
s[a]=ptr1->get_data()+'0';
a++;
s[a]=' ';
}
else{
b=ptr1->get_data();
while(b!=0){
c=b%10;
sum=sum*10+c;
b=b/10;
}
while(sum!=0){
c=sum%10;
s[a]=c+'0';
sum=sum/10;
a++;
}
}
ptr1=ptr1->get_next();
}
return s;
}
int operator [](int i){
Node *ptr1=get_head();
while(ptr1!=NULL){
if(i--){
break;
}
ptr1=ptr1->get_next();
}
return ptr1->get_data();
}
Linklist operator+(Linklist l1){
Linklist l2;
Node *ptr1=get_head();
while(ptr1!=NULL){
l2.add_node(4444);
ptr1=ptr1->get_next();
}
Node *ptr=l1.get_head();
while(ptr1!=NULL){
l2.add_node(4);
ptr1=ptr1->get_next();
}
return l2;
}
void operator+=(Linklist l1){
Node *ptr1=l1.get_head();
while(ptr1!=NULL){
this->add_node(4);
}
}
void operator+=(int value){
this->add_node(20);
}
int operator==(Linklist l1){
Node *ptr1=l1.get_head();
Node *ptr=this->get_head();
while(ptr1!=NULL||ptr!=NULL){
if(ptr->get_data()!=ptr1->get_data()){
return 0;
}
}
return 1;
}
int operator!=(Linklist l1){
Node *ptr1=l1.get_head();
Node *ptr=this->get_head();
while(ptr1!=NULL||ptr!=NULL){
if(ptr->get_data()!=ptr1->get_data()){
return 1;
}
}
return 0;
}
void print_all(){
Node *ptr1=get_head();
while(ptr1!=NULL){
cout<<ptr1->get_data()<<endl;
ptr1=ptr1->get_next();
}
}
};
int main(){
Linklist l1,l2;
int n=4,p=4,h=4,q=4,flag=0,g;
while(1){
cout<<"press 1 to add node"<<endl;
cout<<"press 2 to clear linklist"<<endl;
cout<<"press 3 to check 2 linklist are equal or not"<<endl;
cout<<"press 4 to print data of specific index"<<endl;
cout<<"press 5 to insert a node on specifix index"<<endl;
cout<<"press 6 to check if linklist is empty or not"<<endl;
cout<<"press 7 to remove specific index"<<endl;
cout<<"press 8 to change data of specific node"<<endl;
cout<<"press 9 to print size of linklist"<<endl;
cout<<"press 10 to make a sublist "<<endl;
cout<<"press 11 to convert list data to string"<<endl;
cout<<"press 12 to quit"<<endl;
cout<<"press 13 to print all data of list"<<endl;
cin>>n;
switch(n){
case 1:cout<<"value:="<<endl;
cin>>g;
 l1.add_node(g);
break;
case 2: l1.clear();
break;
case 3: cout<<l1.equal(l2)<<endl;
break;
case 4: cout<<"get index=";
cin>>p;
 cout<<endl<<l1.get(p)<<endl;;
break;
case 5: cout<<"insert index and value=";
cin>>p>>h;
l1.insert(p,h);
break;
case 6: cout<<endl<<l1.isempty()<<endl;
break;
case 7:cout<<"enter index=";
cin>>p;
 l1.remove(p);
break;
case 8: cout<<"enter index and value";
 l1.set(p,q);
break;
case 9: cout<<endl<<l1.size()<<endl;
break;
case 10: cout<<"enter start point and end point";
cin>>p>>q;
 l1.subList(p,q);
break;
case 11: l1.toString();
break;
case 12: flag=1;
break;
case 13: l1.print_all();
break;
default: cout<<"wrong choice";
}
if(flag)
break;
}
return 0;

}
