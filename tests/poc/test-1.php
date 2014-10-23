<?php

dl('paxb.so');

$loader = new Phalcon\Loader;
$loader->registerNamespaces([
    'Api' => __DIR__ . '/src/',
    'PAXB\Binding\Annotations\Xml' => __DIR__ . '/../../src/Binding/Annotations/Xml',
    'PAXB\Tests' => __DIR__ . '/../unit/src/',
]);
$loader->register();

include '../unit/bootstrap.php';


$entity = new Api\TypeDto([
    'id' => 123,
    'name' => 'Full Physical',
    'isBatchable' => true,
    'checkPhysical' => false,
]);
$response = \PAXB\Setup::getMarshaller()->marshall($entity, true);

/*
$xml = file_get_contents('type.xml');
$entity = PAXB\Setup::getUnmarshaller()->unmarshall($xml, 'Api\TypeDto');
var_dump($entity);
*/

d();

