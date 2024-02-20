#include <iostream>
#include <string>

using namespace std;

template <typename T>
class stack;

template <typename T>
class Node
{
	friend class stack<T>;
	
	private:
		T data;
		Node<T>* prev;
		Node<T>* next;
	
	public:
		Node(T data, Node<T>* prev=NULL, Node<T>* next=NULL)
		{
			this->data = data;
			this->prev = prev;
			this->next = next;
		}
};

template <typename T>
class stack
{
	private:
		Node<T>* head;
		Node<T>* tail;
		int size;
	
	public:
		stack()
		{
			head = tail = NULL;
			size=0;
		}
	
		int getSize()
		{
			return size;
		}
	
		void push(T data)
		{
			if(getSize()==0)
			{
				head = new Node<T>(data);
				tail = head;
				++size;
			}
			
			else
			{
				tail->next = new Node<T>(data);
				tail->next->prev = tail;
				tail = tail->next;
				++size;
			}
		}
	
		void top()
		{
			if(empty())
				cout<<"-1\n";
			else
				cout<<tail->data<<'\n';
		}
	
		int empty()
		{
			if(head==NULL)
				return 1;
			else
				return 0;
		}
	
		int pop()
		{
			if(empty())
				return -1;
			else
			{
				int temp = tail->data;
				if(getSize()==1)
				{
					delete head;
					tail=head=NULL;
				}
				else
				{
					tail = tail->prev;
					delete tail->next;
					tail->next = NULL;
				}
				--size;
				return temp;
			}
		}
	
		~stack()
		{
			while(head!=NULL)
			{
				if(empty())
					break;
				else
					pop();
			}
		}
};

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string cmd;
	int data,N;
	cin>>N;
	
	stack<int> s;
	
	for(int i=0; i<N; ++i)
	{
		cin>>cmd;

		if(cmd=="push")
		{
			cin>>data;
			s.push(data);
		}
		
		if(cmd=="pop")
			cout<<s.pop()<<'\n';
		
		if(cmd=="size")
			cout<<s.getSize()<<'\n';

		if(cmd=="empty")
			cout<<s.empty()<<'\n';
		
		if(cmd=="top")
			s.top();
	}
	
	return 0;
}
