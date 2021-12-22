import random
import numpy as np

# helpers

def RightTurn(p1, p2, p3):
	if (p3[1]-p1[1])*(p2[0]-p1[0]) >= (p2[1]-p1[1])*(p3[0]-p1[0]):
		return False
	return True
	
# Chương trình chính
def convexHull(P):
	P.sort()			# Sắp xếp các điểm
	L_upper = [P[0], P[1]]		# Khởi tạo mảng Lupper
	# Kiểm tra và tính toán để thu được mảng Lupper 
	for i in range(2,len(P)):
		L_upper.append(P[i])
		while len(L_upper) > 2 and not RightTurn(L_upper[-1],L_upper[-2],L_upper[-3]):
			del L_upper[-2]
	L_lower = [P[-1], P[-2]]	# Khởi tạo mảng Lower
	# Kiểm tra và tính toán để thu được mảng Lower
	for i in range(len(P)-3,-1,-1):
		L_lower.append(P[i])
		while len(L_lower) > 2 and not RightTurn(L_lower[-1],L_lower[-2],L_lower[-3]):
			del L_lower[-2]
	del L_lower[0]
	del L_lower[-1]
	L = L_upper + L_lower		# Dãy bao bọc cuối cùng
	return np.array(L)


if __name__ == '__main__':
    points = np.array([[0.2, 0.2],
                       [0.2, 0.4],
                       [0.4, 0.4],
                       [0.4, 0.2],
                       [0.3, 0.6]])
    c = convexHull(points)
    print(c)