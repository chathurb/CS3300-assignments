// Valid override

class Extended {
    public static void main(String[] a) {
        System.out.println(new Check().func());
    }
}

class Check {
    public int func() {
        A o1; 
        B o2; 
        C o3; 
        o1 = new B();
        o2 = new B();
        o3 = new C();
        return 0;
    }
}

class A {
}

class B  extends A{
}

class C {
    public A func(A t) {
        return new B();
    }
}

class D extends C {
    // Override
    public B func(A t) {
        return new B();
    }
}


