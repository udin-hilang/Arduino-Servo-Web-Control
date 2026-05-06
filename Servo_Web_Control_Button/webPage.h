String html = R"rawliteral(<html>
    <head>
      <style>
        h1 {
          font-family: Arial;
          font-size: 100px;
          font-weight: bold;
          font-style: italic;
          background-color:rgb(16, 34, 55);
          color: white;
          height: 120px;
          border-radius: 40px;
        }
        
        button {
          color: white;
          font-family: Arial;
          font-weight: bold;
          font-style: italic;
          font-size : 50px;
          height : 100px;
          width : 200px;
          border-radius : 25px;
          transition: all 0.2s;
        }

        button:active {
          height: 80;
          width: 160;
        }

        .buttonOn {
          background-color: green;
        }

        .buttonOn:active {
          background-color: rgb(58, 255, 58);
        }

        .buttonOff {
          background-color: rgb(176, 0, 0);
        }

        .buttonOff:active {
          background-color: rgb(255, 47, 47);
        }

        body {
          background-color: rgb(0, 19, 40);
        }
      </style>
      <title>
        KONTROL LED
      </title>
    </head>
      
      <h1 align="center"><b>KONTROL SERVO</b></h1>
      <body>
        <center>
          <a href="/Left"><button class="buttonOn">LEFT</button></a>
          <a href="/Stop"><button class="buttonOff">STOP</button></a>
          <a href="/Right"><button class="buttonOn">RIGHT</button></a>
        </center>
      </body>
    </html>)rawliteral";
