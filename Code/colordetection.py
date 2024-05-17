import serial
import cv2
import numpy as np

arduino = serial.Serial('COM3', 9600)  # Adjust COM port accordingly

cap = cv2.VideoCapture(0)

while True:
    ret, frame = cap.read()
    hsv = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)
    
    # Define color ranges for red, green, and blue
    red_lower = np.array([0, 100, 100])
    red_upper = np.array([10, 255, 255])
    green_lower = np.array([45, 100, 100])
    green_upper = np.array([75, 255, 255])
    blue_lower = np.array([100, 100, 100])
    blue_upper = np.array([130, 255, 255])
    
    mask_red = cv2.inRange(hsv, red_lower, red_upper)
    mask_green = cv2.inRange(hsv, green_lower, green_upper)
    mask_blue = cv2.inRange(hsv, blue_lower, blue_upper)
    
    if cv2.countNonZero(mask_red) > 1000:
        arduino.write(b'R')  # Send 'R' to Arduino for red color
    elif cv2.countNonZero(mask_green) > 1000:
        arduino.write(b'G')  # Send 'G' to Arduino for green color
    elif cv2.countNonZero(mask_blue) > 1000:
        arduino.write(b'B')  # Send 'B' to Arduino for blue color
    
    cv2.imshow('Frame', frame)
    
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

cap.release()
cv2.destroyAllWindows()
