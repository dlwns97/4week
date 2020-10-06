#include "Array.h"

template <typename T>
class GrowableArray : public Array<T>
{
public:
	GrowableArray(int n) : Array<T>::Array(n) {}
	virtual T& operator[](int i){
		if(i>=Array<T>::len){
			resize(Array<T>::len);
		}
		return Array<T>::operator[](i);
	}
	virtual T operator[](int i)const{
		return Array<T>::operator[](i);
	}
	void resize(int i)
	{
		T* temp;
		temp = new T[i*2];
		memset(temp, 0,sizeof(T)*(i*2));

		for(int k=0;k<Array<T>::len;k++){
			temp[k] = Array<T>::data[k];
		}
		Array<T>::len = i*2;
		delete[] Array<T>::data;
		Array<T>::data = temp;
	}
};
