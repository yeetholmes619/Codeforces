for((i = 0;; i++)) do
        echo $i
        ./gen $i > t1
        ./brute < t1 > o1
        ./b < t1 > o2
        diff -w o1 o2 || break
done
