import cv2
import numpy as np
from PIL import Image
def test():
    # img = Image.open(r"../PIC/human_face_1.jpg")
    # print(img.mode)
    img = cv2.imread(r"../PIC/human_face_1.jpg",cv2.IMREAD_UNCHANGED)
    r = img[:,:,2]
    g = img[:,:,1]
    b = img[:,:,0]
    
    cv2.imshow("r",r)
    cv2.imshow("g",g)
    cv2.imshow("b",b)
    
    img[:,:,2] = 0
    cv2.imshow("img1",img)
    
    cv2.waitKey()
    cv2.destroyAllWindows()
    
if __name__ == "__main__":
    test()