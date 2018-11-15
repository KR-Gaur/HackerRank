#include<iostream>
using namespace std;

class security {

	public:
	void presentValue()
	{
		cout<<"Security Present value"<<endl;
	}
	void history()
	{
		cout<<"history in security"<<endl;
	}

};

class cashAccount : public security {

	int interestRate;

	public:
	void presentValue()
	{
		cout<<"Cash Account Present value"<<endl;
	}

};

class stock :public security {

	public:
	void presentValue()
	{
		cout<<"Stock Present value"<<endl;
	}

};
class bond :public security {

	public:
	void presentValue()
	{
		cout<<"bond Present value"<<endl;
	}
};
int main()
{
	stock st;
	bond b;
	cashAccount ca;
	
	st.history();
	st.security::presentValue();
	
	b.presentValue();
	b.history();
	ca.presentValue();
	ca.history();
	
	return 0;
}
