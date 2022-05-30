<h1 style="text-align: center;">EGG INCUBATOR</h1>
<ul>
<li style="text-align: left;">
<h3><strong>Members:</strong></h3>
<ol type=1>
<li style="text-align: left;">Mohammad Sakib Chowdhury</li>
<li style="text-align: left;">Md Iftikhar Mahmud</li>
<li style="text-align: left;">Muhammad Tahsin Abrar</li>
</ol>
</li>
<li>
<h3><strong>Objective:&nbsp;</strong></h3>
<ul>
<li style="text-align: justify;">An incubator is a device simulating avian incubation by keeping eggs warm at a particular temperature range and in the correct humidit to hatch them. Fertile eggs can be hatched by using an egg incubator.</li>
</ul>
</li>
</ul>
<ul>
<li>
<h3><strong>Theory of hatching:&nbsp;</strong>&nbsp;</h3>
<ul>
<li style="text-align: justify;">&nbsp;An egg incubator is used to hatch bird or reptile eggs. The incubator keeps the eggs warm, allowing the fetuses inside of them to grow and hatch without the mother present. In our project, we are using chicken eggs. The perfect environment for hatching a chicken egg maintains two things; Optimal temperature which is around 35 &ndash; 38 C and humidity which should be around 50% &ndash; 70%. This procedure takes 17 &ndash; 18 days for hatching chicken eggs. Egg needs to be rotated 2 times a day.&nbsp;</li>
</ul>
</li>
</ul>
<ul>
<li>
<h3><strong>Necessary Components:&nbsp;</strong></h3>
<ol type=1>
<li>
<p>Arduino UNO R3</p>
</li>
<li>
<p>DHT22(Temperature &amp; humidity Sensor)</p>
</li>
<li>
<p>LCD</p>
</li>
<li>
<p>Relay (5V)</p>
</li>
<li>
<p>Bulb (20W)</p>
</li>
<li>
<p>Fan (12V_DC)</p>
</li>
<li>
<p>Breadboard</p>
</li>
<li>
<p>Jumper wire</p>
</li>
<li>
<p>Container box</p>
</li>
<li>
<p>Bulb holder</p>
</li>
<li>
<p>Water pot for humidity&nbsp;</p>
</li>
</ol>
</li>
<li>
<h3><a href="https://3dwarehouse.sketchup.com/ar-view/dddab2b3-1740-4511-a05b-d3c5b2e60ab4#model-viewer-no-ar-fallback">3d Model&nbsp;</a></h3>
</li>
<li>
<h3><strong>Arduino Code:&nbsp;</strong></h3>
<ul>
<li>
<div>#include "DHT.h"</div>
<div>#include &lt;LiquidCrystal.h&gt;</div>
<div>#define dht_1 2</div>
<div>#define DHTTYPE DHT22</div>
<div>int Contrast = 75;</div>
<div>LiquidCrystal lcd(12, 11, 7, 5, 4, 3);</div>
<div>DHT dht(dht_1, DHTTYPE);</div>
<div>int FAN = 13;</div>
<div>int light = 8;</div>
<div>volatile byte relayState = LOW;</div>
<div>void setup()</div>
<div>{</div>
<div>&nbsp; &nbsp; pinMode(FAN, OUTPUT);</div>
<div>&nbsp; &nbsp; pinMode(light, OUTPUT);</div>
<div>&nbsp; &nbsp; Serial.begin(9600);</div>
<div>&nbsp; &nbsp; analogWrite(6, Contrast);</div>
<div>&nbsp; &nbsp; lcd.begin(16, 2);</div>
<div>&nbsp; &nbsp; dht.begin();</div>
<div>}</div>
<strong><strong><br /></strong></strong>
<div>void loop()</div>
<div>{</div>
<div>&nbsp; &nbsp; delay(250);</div>
<strong><strong><br /></strong></strong>
<div>&nbsp; &nbsp; float humid = dht.readHumidity();</div>
<div>&nbsp; &nbsp; float temp = dht.readTemperature();</div>
<div>&nbsp; &nbsp; if (humid &lt;= 50)</div>
<div>&nbsp; &nbsp; &nbsp; &nbsp; digitalWrite(FAN, LOW);</div>
<div>&nbsp; &nbsp; if (humid &gt; 60)</div>
<div>&nbsp; &nbsp; &nbsp; &nbsp; digitalWrite(FAN, HIGH);</div>
<div>&nbsp; &nbsp; if (temp &gt;= 38)</div>
<div>&nbsp; &nbsp; {</div>
<div>&nbsp; &nbsp; &nbsp; &nbsp; if (temp &gt;= 40)</div>
<div>&nbsp; &nbsp; &nbsp; &nbsp; {</div>
<div>&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; digitalWrite(light, LOW);</div>
<div>&nbsp; &nbsp; &nbsp; &nbsp; }</div>
<div>&nbsp; &nbsp; &nbsp; &nbsp; else</div>
<div>&nbsp; &nbsp; &nbsp; &nbsp; {</div>
<div>&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; digitalWrite(light, HIGH);</div>
<div>&nbsp; &nbsp; &nbsp; &nbsp; }</div>
<div>&nbsp; &nbsp; }</div>
<div>&nbsp; &nbsp; if (temp &lt; 34)</div>
<div>&nbsp; &nbsp; {</div>
<div>&nbsp; &nbsp; &nbsp; &nbsp; if (temp &lt; 32)</div>
<div>&nbsp; &nbsp; &nbsp; &nbsp; {</div>
<div>&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; digitalWrite(light, HIGH);</div>
<div>&nbsp; &nbsp; &nbsp; &nbsp; }</div>
<div>&nbsp; &nbsp; &nbsp; &nbsp; else</div>
<div>&nbsp; &nbsp; &nbsp; &nbsp; {</div>
<div>&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; digitalWrite(light, LOW);</div>
<div>&nbsp; &nbsp; &nbsp; &nbsp; }</div>
<div>&nbsp; &nbsp; }</div>
<strong><strong><br /></strong></strong>
<div>&nbsp; &nbsp; lcd.setCursor(0, 0);</div>
<div>&nbsp; &nbsp; lcd.print("Humidity : ");</div>
<div>&nbsp; &nbsp; lcd.print(humid);</div>
<div>&nbsp; &nbsp; lcd.setCursor(0, 1);</div>
<div>&nbsp; &nbsp; lcd.print("Temp : ");</div>
<div>&nbsp; &nbsp; lcd.print(temp);</div>
<div>}</div>
</li>
</ul>
</li>
<li>
<h3>Arduino port configuration:&nbsp;</h3>
<ul>
<li>
<table>
<tbody>
<tr>
<td style="text-align: center;"><strong>Component </strong><br /><strong>port </strong></td>
<td style="text-align: center;"><strong>Arduino </strong><br /><strong>port </strong></td>
</tr>
<tr>
<td style="text-align: center;">vss</td>
<td style="text-align: center;">gnd&nbsp;</td>
</tr>
<tr>
<td style="text-align: center;">vdd</td>
<td style="text-align: center;">5v&nbsp;</td>
</tr>
<tr>
<td style="text-align: center;">ro</td>
<td style="text-align: center;">6&nbsp;</td>
</tr>
<tr>
<td style="text-align: center;">rs</td>
<td style="text-align: center;">12&nbsp;</td>
</tr>
<tr>
<td style="text-align: center;">rw&nbsp;</td>
<td style="text-align: center;">Gnd&nbsp;</td>
</tr>
<tr>
<td style="text-align: center;">e</td>
<td style="text-align: center;">11&nbsp;</td>
</tr>
<tr>
<td style="text-align: center;">d4</td>
<td style="text-align: center;">5&nbsp;</td>
</tr>
<tr>
<td style="text-align: center;">d5</td>
<td style="text-align: center;">4&nbsp;</td>
</tr>
<tr>
<td style="text-align: center;">d6</td>
<td style="text-align: center;">3&nbsp;</td>
</tr>
<tr>
<td style="text-align: center;">d7</td>
<td style="text-align: center;">2&nbsp;</td>
</tr>
<tr>
<td style="text-align: center;">A&nbsp;</td>
<td style="text-align: center;">5v&nbsp;</td>
</tr>
<tr>
<td style="text-align: center;">K&nbsp;</td>
<td style="text-align: center;">gnd&nbsp;</td>
</tr>
<tr>
<td style="text-align: center;">Fan&nbsp;</td>
<td style="text-align: center;">13&nbsp;</td>
</tr>
<tr>
<td style="text-align: center;">DHT22&nbsp;</td>
<td style="text-align: center;">2&nbsp;</td>
</tr>
<tr>
<td style="text-align: center;">Relay&nbsp;</td>
<td style="text-align: center;">8&nbsp;</td>
</tr>
</tbody>
</table>
</li>
</ul>
</li>
<li>
<h3>Observation:</h3>
<ul>
<li style="text-align: justify;">The report represents the design and development of a chicken egg incubator. We aim to design and construct an &ldquo;Egg incubator&rdquo; that can hatch chicken eggs automatically. In our design, we used a temperature control system that controls the temperature of the incubator. This system consists of a DHT22 sensor which will provide us with temperature and humidity, cooling elements, and a bulb. If the temperature of the incubator exceeds a certain value, the cooling unit will operate to reduce the temperature while if the temperature goes below another threshold value, the heating element will start to operate to increase the temperature. Furthermore, we used a dimmer circuit to control the lighting conditions of the incubators. If the light level inside the incubators is below the required threshold, lamps inside the incubators will switch ON, otherwise, the lamp will be OFF.&nbsp;The egg incubator consists of two main blocks, which they are the temperature controller block and the humidity control block. First of all, the temperature control block contains a fan circuit and heater circuit to keep the egg incubator temperature suitable for the eggs. The second is the humidity control block which consists of a water pot which reacts with environment temperature to create humidity. All of them are supplied by a 5v power supply. This incubator has an LCD to allow the user to see the temperature and humidity inside the incubator.&nbsp;</li>
</ul>
</li>
<li>
<h3>Light:</h3>
<ul>
<li style="text-align: justify;">The purpose of this component is to control the temperature also inside the egg incubator by keeping the egg warm in its real environment. This component opens the heater when the temperature value goes below the adjusted temperature. On the other hand, it turned off when the temperature value increase above the adjusted value range.</li>
</ul>
</li>
<li>
<h3>Fan:</h3>
<ul>
<li style="text-align: justify;">The purpose of this component is to distribute temperature in the fixed environment (In our case, the box). When temparature is belo 50%, this component will turn off to give the system time to build up humidity.</li>
<li>The objectives behind the project were fulfilled, from understanding the art of constructing circuits to creating our electrical drill!! Add to that the acquired experience in facing the different types of problems and brainstorming their solutions. In the end; the egg incubator worked successfully.</li>
</ul>
</li>
<li>
<h3>Discussion:&nbsp;</h3>
<ul>
<li style="text-align: justify;">Physical exchanges between eggs and the environment are required for the development. Deficient exchanges negatively affect the incubation process, while excessive exchanges may improve incubation efficiency. Physical exchanges depend firstly on eggshell porosity and conductance and temperature and relative humidity differences between the eggs and the environment. These factors are maternally influenced by egg quality (weight, size, chemical composition, eggshell porosity, surface area, and conductance), egg storage conditions (temperature, relative humidity, air velocity) and duration, and the incubation conditions (temperature, relative humidity, egg turning and position at setting, and air velocity and gas concentrations). The maternal effects on the physical exchanges show that the optimal storage and incubation conditions vary with breeder age and egg weight. However, optimal storage and incubation conditions as a function of egg weight or weight range still need to be established. Although this proposal seems to be unrealistic at first sight, it may be feasible as the control systems of incubation physical conditions are further technologically developed, allowing their easier and quicker determination. In addition, incubation conditions, which are essential for maximizing the production efficiency of hatcheries, may be optimized.</li>
</ul>
</li>
</ul>
<p>&nbsp;</p>
<div id="gtx-trans" style="position: absolute; left: 196px; top: 560.775px;">&nbsp;</div>
