#ifndef __ARRAY__
#define __ARRAY__

#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

template <typename T>
class Array{
protected:
	T*data;
	int len;
public:
	Array(int size){
		if(size<=0){
			cout<<"Error!"<<endl;
			exit(1);
		}
		data = new T[size];
		len = size;
	}
	~Array() { delete[] data; }
	virtual T& operator[](int i){
		static T tmp = -1;
		if(i<0||i>len){
			cout<<"Array bound error!"<<endl;
			return tmp;
		}
		return data[i];
	}
	virtual T operator[](int i)const{
		if(i<0||i>len){
			cout<<"Array bound error!"<<endl;
			return -1;
		}
		return data[i];
	}
	int length(){return len;}
	void print(){
		cout<<'[';
		for(int i=0;i<len;i++){
			cout<<data[i];
			if(i!=len-1)
				cout<<' ';
		}
		cout<<']'<<endl;
	}
};
#endif 
