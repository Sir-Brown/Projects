# D'Jaine Brown
# Assignment 3
# 04/20/2026
'''
This program aims to design and implement a small smart home automation system using a combination of the following three different design patterns:
    Observer: will be used to allow devices to subscribe to updates from the central hub.
    Strategy: will be used to enable different control algorithms for the devices.
    Factory: will be used to facilitate the creation of different types of smart devices.

The system will consist of various smart devices (e.g., smart lights, smart thermostats, security cameras) that can be controlled and monitored through a central hub. 
'''

from abc import ABC, abstractmethod
from typing import List, Dict
import time

# Observer Pattern - Event handling
class smart_Device(ABC):
    @abstractmethod
    def update(self, message: str, data) -> None:
        pass

class smart_Light(smart_Device):
    def __init__(self, name: str) -> None:
        self.name = name
        self.active = False
    
    def activate(self) -> None:
        if not self.active:
            self.active = True
            print(f"{self.name} is now active.")

    def deactivate(self) -> None:
        if self.active:
            self.active = False
            print(f"{self.name} is now inactive.")

    def update(self, message: str, data) -> None:
        if message == "motion_detected":
            self.activate()
        elif message == "no_motion" or message == "lights_Off":
            self.deactivate()
        elif message == "time_OfDay":
            if data == "evening" or data == "night":
                self.activate()
            elif data == "morning" or data == "afternoon":
                self.deactivate()

class smart_Thermostat(smart_Device):
    def __init__(self, name: str) -> None:
        self.name = name
        self.temperature = 71.6
    
    def change_Temp(self, temp) -> None:
        print(f"{self.name} is adjusting from {self.temperature}°F to {temp}°F.")
        self.temperature = float(temp)

    def update(self, message: str, data) -> None:
        if message == "temperature_change":
            self.change_Temp(data)

class smart_Camera(smart_Device):
    def __init__(self, name: str) -> None:
        self.name = name
        self.active = False
    
    def start_Recording(self) -> None:
        if not self.active:
            self.active = True
            print(f"{self.name} has started recording.")

    def stop_Recording(self) -> None:
        if self.active:
            self.active = False
            print(f"{self.name} has stopped recording.")

    def update(self, message: str, data) -> None:
        if message == "motion_detected":
            self.start_Recording()
        elif message == "no_motion":
            self.stop_Recording()

class smart_HomeHub:
    def __init__(self):
        self.devices: List[smart_Device] = []
    
    def add_Device(self, device: smart_Device) -> None:
        self.devices.append(device)
    
    def change_Status(self, message: str, data) -> None:
        for device in self.devices:
            device.update(message, data)

# Strategy Pattern - Control algorithms/Automation modes
class automation_Mode(ABC):
    @abstractmethod
    def execute(self, hub: smart_HomeHub, sensor_data) -> None:
        pass

class dusk_to_dawn_Mode(automation_Mode):
    def execute(self, hub: smart_HomeHub, sensor_data) -> None:
        
        # Turn off non-essential devices
        if sensor_data.get("motion_detected", False) == False:
            hub.change_Status("no_motion", None)
        
        # Adjust thermostat based on time of day
        if sensor_data.get("temperature", 71.6) > 77.4:
            hub.change_Status("temperature_change", 72.7)
        elif sensor_data.get("temperature", 71.6) < 68.0:
            hub.change_Status("temperature_change", 70.0)

class comfort_Mode(automation_Mode):
    def execute(self, hub: smart_HomeHub, sensor_data) -> None:
        
        # Turn on lights
        if sensor_data.get("time") in ["evening", "night", "day"]:
            hub.change_Status("time_OfDay", "evening")
        
        # Adjust thermostat:
        hub.change_Status("temperature_change", 71.6)

        # Arm security cameras
        if sensor_data.get("motion_detected", False) == True:
            hub.change_Status("motion_detected", None)
        else:
            hub.change_Status("no_motion", None)

class security_Protocol(automation_Mode):
    def execute(self, hub: smart_HomeHub, sensor_data) -> None:
        
        # Arm security cameras
        if sensor_data.get("motion_detected", False) == True:
            hub.change_Status("motion_detected", None)
        else:
            hub.change_Status("no_motion", None)

        # Adjust thermostat to energy-saving mode
        hub.change_Status("temperature_change", 65.0)

        # Turn off lights
        hub.change_Status("lights_Off", None)

# Factory Pattern - Device creation
class smart_DeviceFactory:
    @staticmethod
    def create_Device(device_type: str, name: str) -> smart_Device:
        if device_type == "light":
            return smart_Light(name)
        elif device_type == "thermostat":
            return smart_Thermostat(name)
        elif device_type == "camera":
            return smart_Camera(name)
        else:
            raise ValueError(f"Unknown device type: '{device_type}'. Available: light, thermostat, camera")
    
    @staticmethod
    def create_AutomationMode(mode_type: str) -> automation_Mode:
        if mode_type == "dusk_to_dawn":
            return dusk_to_dawn_Mode()
        elif mode_type == "comfort":
            return comfort_Mode()
        elif mode_type == "security":
            return security_Protocol()
        else:
            raise ValueError(f"Unknown mode type: {mode_type}")
        
# Main Program
def main():
    print("=" * 60)
    print("Smart Home Automation System")
    print("=" * 60)

    # Create the central hub
    hub = smart_HomeHub()

    # Create devices using the factory
    factory = smart_DeviceFactory()
    smart_LightR = factory.create_Device("light", "Govee Room Light")
    smart_LightLR = factory.create_Device("light", "Govee Living Room Light")
    smart_Thermostat = factory.create_Device("thermostat", "Nest Thermostat")
    smart_Camera = factory.create_Device("camera", "Ring Security Camera")

    # Add devices to the hub
    hub.add_Device(smart_LightR)
    hub.add_Device(smart_LightLR)
    hub.add_Device(smart_Thermostat)
    hub.add_Device(smart_Camera)

    # Create example scenarios to test the system

    # Scenario 1
    print("\n" + "-" * 60)
    print("Scenario 1: Motion detected at night (Security Protocol)")
    print("-" * 60)

    security_Mode = factory.create_AutomationMode("security")
    sensor_data = {
        "motion_detected": True,
        "temperature": 71.6,
        "time": "night"
    }
    security_Mode.execute(hub, sensor_data)

    # Scenario 2
    print("\n" + "-" * 60)
    print("Scenario 2: Evening at home (Comfort Mode)")
    print("-" * 60)

    comfort_Mode = factory.create_AutomationMode("comfort")
    sensor_data = {
        "motion_detected": True,
        "temperature": 68.4,
        "time": "day"
    }
    comfort_Mode.execute(hub, sensor_data)

    # Scenario 3
    print("\n" + "-" * 60)
    print("Scenario 3: Dusk to Dawn (Dusk to Dawn Mode)")
    print("-" * 60)

    dusk_to_dawn_Mode = factory.create_AutomationMode("dusk_to_dawn")
    sensor_data = {
        "motion_detected": False,
        "temperature": 73.0,
        "time": "evening"
    }
    dusk_to_dawn_Mode.execute(hub, sensor_data)

if __name__ == "__main__":
    main()