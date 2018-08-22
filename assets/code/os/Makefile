all: n_processes smem_consumer smem_producer pi pi_n_processes queue_producer queue_consumer

n_processes: n_processes.cpp
	g++ -o n_processes n_processes.cpp

smem_consumer: smem_consumer.cpp
	g++ -o smem_consumer smem_consumer.cpp -lrt

smem_producer: smem_producer.cpp
	g++ -o smem_producer smem_producer.cpp -lrt

pi: pi.cpp
	g++ -o pi pi.cpp

pi_n_processes: pi_n_processes.cpp
	g++ -o pi_n_processes pi_n_processes.cpp -lrt

queue_producer: queue_producer.cpp
	g++ -o queue_producer queue_producer.cpp -lrt

queue_consumer: queue_consumer.cpp
	g++ -o queue_consumer queue_consumer.cpp -lrt
	
.PHONY: clean
clean:
	rm -rf n_processes smem_consumer smem_producer pi

# ipcs -m
