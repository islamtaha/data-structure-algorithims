#ifndef __ARRAY_LIST_H__
#define __ARRAY_LIST_H__


namespace algo{

template<class T>
class ArrayList
{
public:
	ArrayList();
	ArrayList(int n);
	~ArrayList();
	void insert(T value);
	void insert(int index, T value);
	T remove(int index);
	T& at(int index);
	T& operator[](int index);
	void clear();
	int size();
private:
	void increaseCapacity();
	int capacity;
	int len;
	T* arr;
};

template<class T>
ArrayList<T>::ArrayList()
{
	capacity = 10;
	len = 0;
	arr = new T[capacity];
}

template<class T>
ArrayList<T>::ArrayList(int n)
{
	capacity = n;
	len = 0;
	arr = new T[capacity];
}

template<class T>
ArrayList<T>::~ArrayList()
{
	delete [] arr;
}


template<class T>
void ArrayList<T>::insert(T value)
{
	if(len == capacity) increaseCapacity();
	arr[len] = value;
	len++;
}

template<class T>
void ArrayList<T>::insert(int index, T value)
{
	if(len == capacity) increaseCapacity();
	if(index > len && index > capacity){
		increaseCapacity();
		arr[index] = value;
		len++;
	}else if(index > len && index <= capacity)
	{
		arr[index] = value;
		len++;
	}
	else
	{
		for (int i = len; i > index; i--)
		{
			arr[i] = arr[i-1];
		}
		arr[index] = value;
	}
}

template<class T>
T ArrayList<T>::remove(int index){
	len--;
	T temp = arr[index];
	for (int i = index; i < len; i++)
	{
		arr[i] = arr[i+1];
	}
	return temp;
}


template<class T>
T& ArrayList<T>::at(int index){
	return arr[index];
}

template<class T>
T& ArrayList<T>::operator[](int index){
	return arr[index];
}

template<class T>
int ArrayList<T>::size(){
	return len;
}

template<class T>
void ArrayList<T>::clear(){
	len = 0;
	T* temp = new T[capacity];
	delete []arr;
	arr = temp;
}

template<class T>
void ArrayList<T>::increaseCapacity(){
	capacity = capacity * 2;
	T* temp = new T[capacity];
	for(int i = 0; i < len; i++)
	{
		temp[i] = arr[i];
	}
	delete[] arr;
	arr = temp;
}
}

#endif
