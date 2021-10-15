#ifndef COMPLEX_H
#define COMPLEX_H
class complex {
	private:
		int a;
		int b;
	public:
		complex();
		~complex();
		complex(int,int);
		complex(const complex&);
		void print();
		int getRe();
		int getIm();
};


#endif
