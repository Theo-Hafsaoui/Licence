#ifndef POLY_H
#define POLY_H
class poly {
	private:
		int ord;
		float* t;
	public:
		poly();
		~poly();
		poly(float*,int);
		poly(const poly&);
		void print();
};
#endif
