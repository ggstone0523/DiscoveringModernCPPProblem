SUBDIRS = ./WritePolygonDataFolder \
	  ./ReadAndCheckPolygonDataFolder

all: target

target:
	for DIRS in $(SUBDIRS); do $(MAKE) -C $$DIRS; done

clean:
	for DIRS in $(SUBDIRS); do $(MAKE) -C $$DIRS clean; done
	rm -rf PolygonVolAndSurAreaData.txt
