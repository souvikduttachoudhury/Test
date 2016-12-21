#include<iostream>
#include<iomanip>
#include<cstring>
using namespace std;
int max_path=0;
typedef class node{
	public:
	string str;
	int length;
	node *link;
	bool visited;
	node(string str){
		this->str=str;
		this->length=str.size();
		this->visited=false;
		this->link=NULL;
	}
}N;
typedef class PriorityQueue{
	public:
	int node_ct;
	node* top=NULL;
	PriorityQueue(){
		node_ct=0;
	}
	bool isempty(){
		if(node_ct==0){
			return true;
		}
		return false;
	}
	void push(string str){
		if(node_ct==0){
			top=new node(str);
			node_ct++;
			return;
		}
		node_ct++;
		node *p=new node(str);
		node *current=top;
		node *next=top->link;
		if(p->length<current->length){
			p->link=current;
			top=p;
			return;
		}
		while(next){
			if(p->length<next->length){
				p->link=next;
				break;
			}
			current=next;
			next=next->link;
		}
		current->link=p;
		return;
	}
	void pop(){
		if(isempty()){
			cout<<"Popping is not possible"<<endl;
			return;
		}
		node *temp=top;
		top=top->link;
		node_ct--;
		//delete(temp);
		return;
	}
	node* gettop(){
		if(isempty()){
			cout<<"Popping is not possible"<<endl;
			return NULL;
		}
		return top;
	}	
}PQ;
bool issubset(string s1,string s2){
	int map[26];
	if(s2==""){
		return true;
	}
	for(int i=0;i<26;i++){
		map[i]=0;
	}
	for(int i=0;i<s1.size();i++){
		int ascii=(int)(s1[i]);
		if(ascii<97){
			ascii=ascii-65;
		}
		else{
			ascii=ascii-97;
		}
		map[ascii]++;
	}
	for(int i=0;i<s2.size();i++){
		int ascii=(int)(s2[i]);
		if(ascii<97){
			ascii=ascii-65;
		}
		else{
			ascii=ascii-97;
		}
		map[ascii]--;
	}
	int flag=0,m;
	for(int i=0;i<26;i++){
		if(map[i]!=0){
			flag++;
			m=i;
		}
	}
	if(flag==1){
		if(map[m]==1){
			return true;
		}
	}
	return false;
}
void calculate(PQ *pq,string s,int len,int path){
	node *temp[100];
	int mrk=0;
	while(!pq->isempty()){
		if(!((pq->gettop())->length==len)){
			break;
		}
		temp[mrk]=pq->gettop();
		pq->pop();
		mrk++;
		//cout<<temp[mrk-1]->str<<endl;
	}
	//cout<<mrk<<endl;
	for(int i=0;i<mrk;i++){
		//cout<<temp[i]->visited<<","<<temp[i]->str<<","<<len+1<<","<<s<<","<<path+1<<endl;
		if(temp[i]->visited){
			continue;
		}
		else if((temp[i]->length)==len){
			if(issubset((temp[i]->str),s)){
				temp[i]->visited=true;
				//cout<<temp[i]->str<<","<<len+1<<","<<path+1<<endl;
				calculate(pq,temp[i]->str,len+1,path+1);
			}
		}
	}
	for(int i=0;i<mrk;i++){
		if(temp[i]->visited){
			continue;
		}
		else{
			//cout<<"pushing: "<<temp[i]->str<<endl;
			pq->push(temp[i]->str);
			//cout<<"pushed: "<<temp[i]->str<<endl;
		}
	}
	if(path>max_path){
		max_path=path;
	}
}
int main(){
	int len;
	cout<<"Enter the no. of elements in the array:"<<endl;
	cin>>len;
	PQ *pq=new PQ();
	string *arr=new string[len];
	cout<<"Enter the elements:"<<endl;
	for(int i=0;i<len;i++){
		cin>>arr[i];
		pq->push(arr[i]);
	}
	/*
	for(int i=0;i<len;i++){
		N* r=pq->gettop();
		cout<<r->str<<","<<r->length<<endl;
		pq->pop();
	}
	cout<<endl;
	*/
	int leng=1;
	while(!pq->isempty()){
		calculate(pq,"",leng,0);
		leng++;	
	}
	cout<<"Maximum Path length is: "<<max_path<<endl;
	//cout<<issubset("cat","ca");
}
