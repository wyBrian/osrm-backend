import osrm

ec = osrm.EngineConfig()
ec.base_path='/mnt/d/work/redmart/osrm/malaysia-singapore-brunei-latest.osrm'
ec.use_mmap=True

sh=osrm.ServiceHandler(ec)
coord1=osrm.Coordinate(1.3545854,103.8388995)
coord2=osrm.Coordinate(1.2989822,103.8209609)
coord3=osrm.Coordinate(1.3388827,103.9057616)

tableParam=osrm.TableParameters()
tableParam.coordinates.append(coord1)
tableParam.coordinates.append(coord2)
tableParam.coordinates.append(coord3)

sh.Table(tableParam)
