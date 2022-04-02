# This script will post data to thingspeak for data visualization
import requests
import serial

portName = "COM9"
buadRate = 9600
apiKey = "5RQ30WGE6AXTYB6W"
thingsUrl = "https://api.thingspeak.com/update?api_key="
serialMonitor = serial.Serial(portName, buadRate)


def readSerial():
    try:
        SerialBytes = serialMonitor.readline()
        data = SerialBytes[0: len(SerialBytes) - 2].decode("utf-8")
        decoded_data = deconstructData(data)
        sendData(decoded_data[0], decoded_data[1])

    except:
        print("you are not working")


def sendData(distance_data, magnetic_reed_data):
    postUrl = "{}{}&field1={}&field2={}".format(
        thingsUrl, apiKey, distance_data, magnetic_reed_data)
    send = requests.get(url=postUrl)


def deconstructData(data):
    decoded_data = data.split("###", 1)
    print("distance is :", decoded_data[0], "reed reading:", decoded_data[1])
    return decoded_data


while True:
    readSerial()
