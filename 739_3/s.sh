for((i = 0;;i++)) do
        echo $i
        ./gen $i > t1
         python hackc.py < t1 > o1
        ./brute < t1 > o2
        diff -w o1 o2 || break
done
