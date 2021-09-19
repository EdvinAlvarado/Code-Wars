int beeramid(double bonus, double price) {
	double tab = 0;
	double l = 0;

	while (tab + price*(l+1)*(l+1) <= bonus) {
		tab += price*++l*l;
	}
	return l;
}
