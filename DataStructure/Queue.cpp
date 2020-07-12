#include <iostream>
#include <string>

using namespace std;

template <typename T>
class queue;

template <typename T>
class Node
{
	friend class queue<T>;
	
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
class queue
{
	private:
		Node<T>* head;
		Node<T>* tail;
		int size;
	
	public:
		queue()
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
	
		int front()
		{
			if(empty())
				return -1;
			else
				return head->data;
		}
	
		int back()
		{
			if(empty())
				return -1;
			else
				return tail->data;
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
				int temp = head->data;
				if(getSize()==1)
				{
					delete head;
					tail=head=NULL;
				}
				else
				{
					head = head->next;
					delete head->prev;
					head->prev = NULL;
				}
				--size;
				return temp;
			}
		}
	
		~queue()
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
	
	queue<int> q;
	
	for(int i=0; i<N; ++i)
	{
		cin>>cmd;

		if(cmd=="push")
		{
			cin>>data;
			q.push(data);
		}
		
		if(cmd=="pop")
			cout<<q.pop()<<'\n';
		
		if(cmd=="size")
			cout<<q.getSize()<<'\n';

		if(cmd=="empty")
			cout<<q.empty()<<'\n';
		
		if(cmd=="front")
			cout<<q.front()<<'\n';
		
		if(cmd=="back")
			cout<<q.back()<<'\n';
	}
	
	return 0;
}
