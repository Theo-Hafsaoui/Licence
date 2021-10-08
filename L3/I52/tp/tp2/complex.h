#ifndef COMPLEX_H
#define COMPLEX_H
class complex {
	private:
		int a;
		int b;
	public:
		complex();
		complex(int,int);
		complex(const complex&);
		void print();
		int getRe();
		int getIm();
		void Sum(const complex&);
		bool Sum(const complex&);
};


#endif
