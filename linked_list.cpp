#include<iostream>
using namespace std;
class Node{
public:
int data;
Node *next;
Node(){
this->data=5;
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
static Node* Create_newnode(){
Node *newnode;
newnode=new Node();
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
void add_node(){
Node *newnode=Node::Create_newnode();
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
Node *newnode=Node::Create_newnode();
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
Node *newnode=Node::Create_newnode();
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
};
int main(){
Linklist l1;
l1.add_node();
l1.add_node();
cout<<l1.last->data<<endl<<l1.head->next->data;
return 0;

}
