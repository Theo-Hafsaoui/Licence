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
		void sum(const complex&);
		void sum1(const complex&);
		complex sum2(const complex&);
		complex sum3(const complex&);
		complex& sum4(const complex&);
		bool identical(const complex&);
		complex operator +(const complex&);
		complex operator -(const complex&);
		complex operator *(const complex&);
		complex operator /(const complex&);
		complex operator =(const complex&);
};


#endif
