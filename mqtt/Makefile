###########################################
### MAKEFILE TO INSTALL AND MANAGE MQTT ###
###########################################

###################
### ENVIRONMENT ###
###################

MOSQUITTO_CONFIG_DIR  = ./mosquitto-config
MOSQUITTO_CONFIG_FILE = mosquitto.conf

DOCKERFILE_DIR = ./dockerfiles
MYMQTT_SERVER_IMG_NAME = mymqttserver
MYMQTT_SERVER_DOCKERFILE = mymqttserver.dockerfile
MYMQTT_SERVER_NAME = broker1

GID := $(shell id -g)
UID := $(shell id -g)

###############
### SUMMARY ###
###############

commands:
	@echo "=== COMMANDS ==="
	@echo ""
	@echo "BUILD_SERVER_IMG  :	Builds the image of an MQTT server"
	@echo "RUN_SERVER        :	Run the MQTT broker"
	@echo "STOP_SERVER       :	Stop the MQTT broker"
	@echo "REMOVE_SERVER     :	Remove the MQTT broker"
	@echo "ATTACH_TO_SERVER  :	Attach to the MQTT SERVER"
	@echo "DEBUG_SERVER      :	Debug the server container"
	@echo ""
	@echo "TEST_PUBLISH      :	Publishing test"
	@echo "TEST_SUBSCRIBER   :	Subscription test"
	@echo ""
	@echo "LIST_CONTAINERS   :	List Docker containers"
	@echo ""

##############################
### COMMAND IMPLEMENTATION ###
##############################
TEST_PUBLISH:
	@echo "Testing publishing"
	mosquitto_pub -i mosq_pub1 -t "Test" -m "Message with ID: 1" -d

TEST_SUBSCRIBER:
	@echo "Testing subscriber"
	mosquitto_sub -i mosq_sub1 -t "Test" -d

DEBUG_SERVER:
	docker logs $(MYMQTT_SERVER_NAME)

BUILD_SERVER_IMG:
	@echo "Building MQTT server image"
	docker buildx build -t $(MYMQTT_SERVER_IMG_NAME) -f $(DOCKERFILE_DIR)/$(MYMQTT_SERVER_DOCKERFILE) .

RUN_SERVER:
	@echo "Running MQTT Broker..."
	id -u
	id -g
	docker run -it -d --name $(MYMQTT_SERVER_NAME) -p 1883:1883 -u $(UID):$(GID) -v $(MOSQUITTO_CONFIG_DIR):/mosquitto/config $(MYMQTT_SERVER_IMG_NAME)

STOP_SERVER:
	@echo "Stopping MQTT Broker..."
	docker stop $(MYMQTT_SERVER_NAME)

REMOVE_SERVER:
	@echo "Removing MQTT Broker..."
	docker rm -f $(MYMQTT_SERVER_NAME)

ATTACH_TO_SERVER:
	@echo "Attaching to the MQTT server..."
	docker exec -it $(MYMQTT_SERVER_NAME) sh

LIST_CONTAINERS:
	docker ps -a
