./gen > new.in
./bad < new.in > bad.out
./good < new.in > good.out

cat new.in

while cmp --silent -- "good.out" "bad.out"
do
	./gen > new.in
	./bad < new.in > bad.out
	./good < new.in > good.out
	cat new.in
done

cat good.out
cat bad.out
