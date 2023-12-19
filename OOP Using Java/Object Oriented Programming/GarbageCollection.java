import java.lang.Runtime;

class GarbageCollection {
    public void finalize(){
        System.out.println("gc() Called!");
    }

    public static void main(String[] args) {
        GarbageCollection g = new GarbageCollection();
        Runtime r = Runtime.getRuntime();

        long mem1, mem2, mem3;

        mem1 = r.totalMemory();
        System.out.println("Total Memory: " + mem1);

        g = null;
        mem2 = r.freeMemory();
        System.out.println("Memory After Assigning Value: " + mem2);

        System.gc();
        mem3 = r.freeMemory();
        System.out.println("Memory After gc: " + mem3);
    }
}
