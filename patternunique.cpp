#include<iostream>
#include<iomanip>
using namespace std;
int main(){
	int n;
	cout<<"Enter the no. of pyramids to be printed:"<<endl;
	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<3;j++){
		for(int k=0;k<3*(n-i-1);k++){
			cout<<" ";
		}
		for(int l=0;l<2-j;l++){
			cout<<" ";
		}
		for(int m=0;m<j+1;m++){
			cout<<"*";
		}
		for(int n=1;n<j+1;n++){
			cout<<"*";
		}
		for(int l=0;l<3-j;l++){
			cout<<" ";
		}
		for(int r=0;r<i;r++){
			for(int l=1;l<3-j;l++){
			cout<<" ";
			}
			for(int m=0;m<j+1;m++){
			cout<<"*";
			}
			for(int n=1;n<j+1;n++){
				cout<<"*";
			}
			for(int l=0;l<3-j;l++){
			cout<<" ";
			}
		}
		cout<<endl;
		}
	}
}
