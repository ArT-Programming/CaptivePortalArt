void handleUDP() {
  int packetSize = Udp.parsePacket();
  if (packetSize) {
    // receive incoming UDP packets
    //Serial.printf("Received %d bytes from %s, port %d\n", packetSize, Udp.remoteIP().toString().c_str(), Udp.remotePort());
    int len = Udp.read(incomingPacket, 255);
    if (len > 0)
    {
      incomingPacket[len] = 0;
    }
    if (incomingPacket[0] == '#') {
      remoteIP = Udp.remoteIP();
    }
    Serial.printf(incomingPacket);


    // send back a reply, to the IP address and port we got the packet from
    Udp.beginPacket(Udp.remoteIP(), Udp.remotePort());
    Udp.write(replyPacekt);
    Udp.endPacket();
  }

  /*
   * Send udp data to Arduino 
   */
  if (stringComplete) {
    Udp.beginPacket(remoteIP, remoteUdpPort);
    Udp.write(inputString);
    Udp.endPacket();
    stringComplete = false;
    //Serial.println("Sent udp stuff");
    //Serial.println(inputString);
    
  }
  return;
}

