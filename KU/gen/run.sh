g++ KU_Board.cpp -o ice
g++ kang.cpp -o kang
./gen 100 100 10 > new.in
./kang < new.in > kang.out
./ice < new.in > ice.out

cat new.in

while cmp --silent -- "ice.out" "kang.out"
do
	./gen 100 100 10 > new.in
	./ice < new.in > ice.out
	./kang < new.in > kang.out
	cat new.in
done
