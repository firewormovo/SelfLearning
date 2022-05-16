import cv2 
from PIL import Image
import numpy as np
def test():
    a = cv2.imread(r"../PIC/human_face_1.jpg",cv2.IMREAD_UNCHANGED) #(1198, 800, 3)
    b = cv2.imread(r"../PIC/dollar.jpeg",cv2.IMREAD_UNCHANGED)
    cv2.imshow("human_face_1",a)
    cv2.imshow("dollar",b)
    # ROI 区域
    roi_a = a[220:800,210:615,:]
    cv2.imshow("roi_a",roi_a)
    
    roi_b = b[207:477,462:636,:]
    cv2.imshow("roi_b",roi_b)
    
    print("roi_a:",roi_a.shape)
    print("roi_b:",roi_b.shape)
    
    # 压缩roi区域
    c = cv2.resize(roi_a,(roi_b.shape[1],roi_b.shape[0]))
    cv2.imshow("c",c)
    
    # 替换
    b[207:477,462:636,:] = c
    cv2.imshow("after change",b)
    
    print(c.shape)
    cv2.waitKey()
    cv2.destroyAllWindows()
    
if __name__=="__main__":
    test()