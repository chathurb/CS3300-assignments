// Comparing incompatible obj

class Extended {
    public static void main(String[] a) {
        System.out.println(new A().go());
    }
}

class A {
    public int go() {
        Class1 c1;
        Class2 c2;
        Class3 c3;
        Class1 c1_2;
        Class1 c1_3;
        Class2 c2_3;
        boolean x;
        c2 = new Class2(); 
        c1 = new Class1();
        c3 = new Class3();
        if (c3 != c2) {
            x = false;
        }
        return 1337;
    }
}

class Class1 {
    public int AMethod() {
        return 0;
    }

    public int BMethod() {
        return 1;
    }

    public int CMethod() {
        return 2;
    }
}

class Class2 extends Class1 {
    public int BMethod() {
        return 3;
    }

    public int DMethod() {
        return 5;
    }
}

class Class3 extends Class1{
    public int AMethod() {
        return 7;
    }

    public int FMethod() {
        return 6;
    }
}