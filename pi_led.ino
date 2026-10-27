import RPi.GPIO as GPIO

LED=17
GPIO.setmode(GPIO.BCM)
GPIO.setup(LED,GPIO.OUT)

try:
  while True:
    command=input("1,0,q")
    if command=='1':
      GPIO.output(LED,GPIO.HIGH)
      print("LED ON")
    elif command=='0':
      GPIO.output(LED,GPIO.LOW)
      print("LED OFF")
    else:
      break
except KeyboardInterrupt:
    print("\nProgram down")
finally:
  GPIO.output(LED,GPIO.LOW)
  GPIO.cleanup()