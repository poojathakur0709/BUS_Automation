import dbus, dbus.mainloop.glib
import sys,os
from gi.repository import GLib

class Ui_MainWindow(object):
        #BLE Variable
    status="playing"
    track = "no Music"
    player_iface = None
    transport_prop_iface = None
    bus = None
    obj = None
    mgr=None 
    #####
    def setupUi(self, MainWindow):
      #######
      ###Ble Tab
      self.BLETAB = QtWidgets.QWidget()
      self.BLETAB.setObjectName("BLETAB")

        #BLE CODE
        
      dbus.mainloop.glib.DBusGMainLoop(set_as_default=True)
      self.bus = dbus.SystemBus()
      self.obj = self.bus.get_object('org.bluez', "/")
      self.mgr = dbus.Interface(self.obj, 'org.freedesktop.DBus.ObjectManager')
        ## 
        ##BLE Button as connect button
        #         
        #self.BluetoothOffLabel.connect(self.bluetooth)
        #        
      ###########
        #BLE  Code before connectivity
        


        for path, ifaces in self.mgr.GetManagedObjects().items():
            if 'org.bluez.MediaPlayer1' in ifaces:
                self.player_iface = dbus.Interface(
                        self.bus.get_object('org.bluez', path),
                        'org.bluez.MediaPlayer1')
                self.bt_player_connect_label.setText("Connected")
                
            elif 'org.bluez.MediaTransport1' in ifaces:
                self.transport_prop_iface = dbus.Interface(
                        self.bus.get_object('org.bluez', path),
                        'org.freedesktop.DBus.Properties')
        time.sleep(1)
        self.bus.add_signal_receiver(
                self.on_property_changed,
                bus_name='org.bluez',
                signal_name='PropertiesChanged',
                dbus_interface='org.freedesktop.DBus.Properties')

# ble functions
    def bluetooth (self):
        #BLE  Code
        
        for path, ifaces in self.mgr.GetManagedObjects().items():
            if 'org.bluez.MediaPlayer1' in ifaces:
                self.player_iface = dbus.Interface(
                        self.bus.get_object('org.bluez', path),
                        'org.bluez.MediaPlayer1')
                self.bt_player_connect_label.setText("Connected")
                
            elif 'org.bluez.MediaTransport1' in ifaces:
                self.transport_prop_iface = dbus.Interface(
                        self.bus.get_object('org.bluez', path),
                        'org.freedesktop.DBus.Properties')
        time.sleep(1)
        self.bus.add_signal_receiver(
                self.on_property_changed,
                bus_name='org.bluez',
                signal_name='PropertiesChanged',
                dbus_interface='org.freedesktop.DBus.Properties')
    
    def on_property_changed(self,interface, changed, invalidated):
        if interface != 'org.bluez.MediaPlayer1':
            return
        for prop, value in changed.items():
            if prop == 'Status':
                print('Playback Status: {}'.format(value))
                self.status = value
                if self.status == "playing":
                    self.bt_play_pause_btn.setIcon(QIcon('/home/pi/Desktop/demo/logos/music_3.svg'))
                elif self.status == "paused":
                    self.bt_play_pause_btn.setIcon(QIcon('/home/pi/Desktop/demo/logos/music_4.svg'))
            elif prop == 'Track':
                self.track = value
                for key in ('Title', 'Artist', 'Album'):
                    print('   {}: {}'.format(key, value.get(key, '')))                    
                    self.bt_player_song_title_label.setText(value.get("Title"))
                    self.bt_player_song_artist_label.setText(value.get("Album"))
                    self.bt_palyer_song_album_label.setText(value.get("Artist"))

    def play_pause(self):
        play = False
        try:
            if self.status == "playing":
                self.player_iface.Pause()        
                self.status = "paused"
            elif self.status == "paused":
                self.player_iface.Play()
                self.status = "playing"
        except  Exception as inst:
            print(inst)

    
    def next_song(self):
        try:
            play = False
            self.player_iface.Next()
        except:
            print("next exc")

        
    
    def previous_song(self):
        try:
            play = False
            self.player_iface.Previous()
        except:
            print("prev excep")
    