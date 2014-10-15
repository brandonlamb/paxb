<?php

$loader = new Phalcon\Loader;
$loader->registerNamespaces([
    'Api' => __DIR__ . '/src/',
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

echo \PAXB\Setup::getMarshaller()->marshall($entity, true);

/*
$xml = file_get_contents('type.xml');
$entity = PAXB\Setup::getUnmarshaller()->unmarshall($xml, 'Api\TypeDto');

var_dump($entity);
*/


d();
