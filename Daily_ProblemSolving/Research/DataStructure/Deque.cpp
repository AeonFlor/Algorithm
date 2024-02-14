#include <iostream>
#include <string>

using namespace std;

template <typename T>
class deque;

template <typename T>
class Node
{
	friend class deque<T>;
	
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
class deque
{
	private:
		Node<T>* head;
		Node<T>* tail;
		int size;
	
	public:
		deque()
		{
			head = tail = NULL;
			size=0;
		}
	
		int getSize()
		{
			return size;
		}
		
		void push_front(T data)
		{
			if(getSize()==0)
			{
				head = new Node<T>(data);
				tail = head;
				++size;
			}
			
			else
			{
				head->prev = new Node<T>(data);
				head->prev->next=head;
				head = head->prev;
				++size;
			}
		}
		
		void push_back(T data)
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
	
		int pop_front()
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
	
		int pop_back()
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
	
		~deque()
		{
			while(head!=NULL)
			{
				if(empty())
					break;
				else
					pop_front();
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
	
	deque<int> q;
	
	for(int i=0; i<N; ++i)
	{
		cin>>cmd;

		if(cmd=="push_front")
		{
			cin>>data;
			q.push_front(data);
		}
		
		if(cmd=="push_back")
		{
			cin>>data;
			q.push_back(data);
		}
		
		if(cmd=="pop_front")
			cout<<q.pop_front()<<'\n';
		
		if(cmd=="pop_back")
			cout<<q.pop_back()<<'\n';
		
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
