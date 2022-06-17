from foo import *
n = 3
m =4
arr = create_arr(n, m)
out_vectors(arr ,n, m)
sum_of_par , par = sum_of_Paralel(arr, n)
sum_of_per  , per = sum_of_Perpen(arr ,n , m)
print(f"sum of parallel vectors to 0-vec R^2: {sum_of_par}")
print(f"sum of parallel vectors to 0-vec R^3: {sum_of_per}")
out_to_zero(par ,"All vectors that paral. to 0-vec :")
out_to_zero(per , "All vectors that perpen. to 0-vec :")