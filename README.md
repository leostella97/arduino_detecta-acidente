# Sistema de Detecção de Acidentes 
## Arduino com shields de Sensor de Inclinação e Módulo GSM

<p>Este código em Arduino foi desenvolvido para criar um sistema de detecção de acidentes veiculares baseado em um sensor de inclinação. Abaixo estão os detalhes sobre o que foi feito, para que foi feito e o que é necessário para o funcionamento adequado do sistema.</p>

### Para que foi feito:
<br>
<p>Este código foi projetado para proporcionar um sistema de alerta de acidentes veiculares. A ideia principal é utilizar um sensor de inclinação, presumivelmente instalado no veículo, para detectar mudanças bruscas na inclinação, o que pode indicar a ocorrência de um acidente. Quando tal evento é detectado, o sistema aciona um módulo GSM para enviar uma mensagem de alerta, indicando a possível necessidade de assistência policial.</p>

### O que precisa para funcionar:
<br>
<table>
	<ol>
		<li>
			<b>Sensor de Inclinação:</b>
			<br>
			• Conecte o sensor de inclinação ao pino especificado (pinoSensorInclinacao). Certifique-se de escolher um sensor apropriado para detectar movimentos bruscos do veículo.
		</li>
		<li>
			<b>Módulo GSM:</b>
			<br>
			• Conecte o módulo GSM ao pino especificado (<code>pinoModuloGSM</code>). Certifique-se de configurar corretamente o módulo GSM para enviar mensagens.
		</li>
		<li>
			<b>Configuração Adequada:</b>
			<br>
			• Ajuste as configurações de acordo com o hardware específico que você está utilizando, como o tipo de sensor de inclinação e as características do módulo GSM.
		</li>
		<li>
			<b>Teste Seguro:</b>
			<br>
			• Antes de implementar em um ambiente de condução real, teste o sistema de forma segura para garantir que está funcionando conforme o esperado. Simule inclinações bruscas para verificar a sensibilidade do sensor.
		</li>
	</ol>
</table>

<table>
	<ol>
		<li>
			<b>Inclusão de Bibliotecas:</b>
			<br>
			• Foram incluídas bibliotecas necessárias para o uso do sensor de inclinação. Entretanto, é importante observar que essas bibliotecas (<i>Adafruit_Sensor, Adafruit_BNO055</i>, etc.) podem não ser necessárias, uma vez que o código utiliza apenas um sensor de inclinação.
		</li>
		<li>
			<b>Definição de Pinagem:</b>
			<br>
			• Os pinos para o sensor de inclinação (pinoSensorInclinacao) e o módulo GSM (pinoModuloGSM) foram definidos. Certifique-se de substituir esses valores pelos pinos reais conectados ao Arduino.
		</li>
		<li>
			<b>Variáveis de Controle:</b>
			<br>
			• Foi criada uma variável <i>booleana</i>, <code>acidenteDetectado</code>, para controlar o estado da detecção de acidente. Entretanto, essa variável não está sendo utilizada no código atual.
		</li>
		<li>
			<b>Configuração Inicial:</b>
			<br>
			No método <code>setup()</code>, os pinos foram configurados como entrada para o sensor de inclinação e saída para o módulo GSM. Além disso, a comunicação serial foi inicializada para permitir o monitoramento.
		</li>
		<li>
			<b>Loop Principal:</b>
			<br>
			No método <code>loop()</code>, o código verifica continuamente o estado do sensor de inclinação. Se uma inclinação brusca for detectada (estado HIGH), a função <code>enviarAlertaAcidente()</code> é chamada.
		</li>
		<li>
			<b>Função para Enviar Alerta de Acidente:</b>
			<br>
			A função enviarAlertaAcidente() ativa o módulo GSM para enviar um alerta, imprime uma mensagem de alerta via Serial e aguarda um tempo antes de desativar o módulo GSM. A variável acidenteDetectado é reiniciada, mas como mencionado anteriormente, ela não é usada no código atual.
		</li>
	</ol>
</table>