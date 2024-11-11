#include <stdio.h>

struct halfadd {
	int out;
	int carry_out;
};

struct fulladd {
	int out;
	int carry_out;
};

int not(int a) {
	if (a == 0) {
		return 1;
	} else {
		return 0;
	}
}

int and(int a, int b) {
	if (a == 1) {
		if (b == 1) {
			return 1;
		} else {
			return 0;
		}
	} else {
		return 0;
	}
}

int or(int a, int b) {
	if (a == 0) {
		if (b == 0) {
			return 0;
		} else {
			return 1;
		}
	} else {
		return 1;
	}
}

int nand(int a, int b) {
	if (a == 1) {
		if (b == 1) {
			return 0;
		} else {
			return 1;
		}
	} else {
		return 1;
	}
}

int nor(int a, int b) {
	if (a == 0) {
		if (b == 0) {
			return 1;
		} else {
			return 0;
		}
	} else {
		return 0;
	}
}

int xor(int a, int b) {
	if (a == b) {
		return 0;
	} else {
		return 1;
	}
}

int xnor(int a, int b) {
	if (a != b) {
		return 0;
	} else {
		return 1;
	}
}

struct halfadd half(int a, int b) {
	int out = xor(a, b);
	int carry;
	if (and(a, b) == 1) {
		carry = 1;
	} else {
		carry = 0;
	}
	struct halfadd Half;
	Half.carry_out = carry;
	Half.out = out;
	return Half;
}

struct fulladd full(int a, int b, int carry_in) {
	carry_in = half(a, b).carry_out;
	int out = xor(xor(a, b), carry_in);
	int carry_out;
	if (a == 0 && b == 0 && carry_in == 0) {
		carry_out = 0;
	} else if (a == 0 && b == 0 && carry_in == 1) {
		carry_out = 0;
	} else if (a == 0 && b == 1 && carry_in == 0) {
		carry_out = 0;
	} else if (a == 0 && b == 1 && carry_in == 1) {
		carry_out = 1;
	} else if (a == 1 && b == 0 && carry_in == 0) {
		carry_out = 0;
	} else if (a == 1 && b == 0 && carry_in == 1) {
		carry_out = 1;
	} else if (a == 1 && b == 1 && carry_in == 0) {
		carry_out = 1;
	} else if (a == 1 && b == 1 && carry_in == 1) {
		carry_out = 1;
	}
	struct fulladd Full;
	Full.out = out;
	Full.carry_out = carry_out;
	return Full;
}

int main() {
	printf("%d%d\n", full(1, 1, 1).carry_out, full(1, 1, 1).out);
}
