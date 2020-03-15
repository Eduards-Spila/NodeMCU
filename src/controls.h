const char controlpage[] PROGMEM = R"=====(
	<!DOCTYPE HTML>
	<html>
		<body>
			<div class="btn-group" style="text-align:center;width:320px;">
				<form action='bothOn'>
					<input class='button' type='submit' value='BOTH LED ON' />
				</form>
				<br>
				<br>
				<form action='l1Toggle'>
					<input class='button' type='submit' value='LED 1 TOGGLE'/>
				</form>
				<form action='l2Toggle'>
					<input class='button' type='submit' value='LED 2 TOGGLE'/>
				</form>
				<br>
				<br>
				<form action='bothOff'>
					<input class='button' type='submit' value='BOTH LED OFF'/>
				</form>
			</div>
		</body>
	</html>
)=====";
