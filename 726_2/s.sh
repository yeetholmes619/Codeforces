for((i = 0;;i++))do
        echo $i
        ./gen $i > t1
        ./e1_up < t1 > o1
        ./e2_up < t1 > o2
        diff -w o1 o2 || break
done
