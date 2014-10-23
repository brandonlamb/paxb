<?php

/**
 * Data Transfer Object for Count Type
 *
 * @package \Api\Dto\Count
 * @copyright Starbucks Coffee Company
 * @author Brandon Lamb <brlamb@starbucks.com>
 */

namespace Api;

use PAXB\Binding\Annotations\Filter;

/**
 * @XmlRootElement(name="type")
 */
class TypeDto extends AbstractDto
{
    /**
     * @XmlElement
     * @var int
     */
    protected $id = 0;

    /**
     * @XmlElement
     * @var string
     */
    protected $name = '';

    /**
     * @XmlElement
     * @Filter\Boolean
     * @var boolean
     */
    protected $isBatchable = false;

    /**
     * @XmlElement
     * @Filter\Boolean
     * @var boolean
     */
    protected $checkPhysical = false;

    /**
     * @XmlElement
     * @Filter\Boolean
     * @var boolean
     */
    protected $checkReceiptDate = false;

    /**
     * @XmlElement
     * @Filter\Boolean
     * @var boolean
     */
    protected $isIncludedInHistory = false;

    /**
     * @XmlElement
     * @var boolean
     */
    protected $isForceToZeroAllowed = false;

    /**
     * @XmlElement
     * @var boolean
     */
    protected $isSuppressAllowed = false;

    /**
     * @XmlElement
     * @var boolean
     */
    protected $isExcludeAllowed = false;

    /**
     * @XmlElement
     * @var string
     */
    protected $referenceCode = '';

    /**
     * @XmlElement
     * @var int
     */
    protected $batchPriority = 0;

    /**
     * @var array
     */
    protected $inventoryTypes = [];

    /**
     * @var array
     */
    protected $specialHandling = [];

    /**
     * Setter for id
     *
     * @param int $value
     */
    public function setId($value)
    {
        $this->id = (int) $value;
    }

    /**
     * Set name
     *
     * @param string $value
     */
    public function setName($value)
    {
        $this->name = trim($value);
    }

    /**
     * Set is batchable flag
     *
     * @param mixed $value
     */
    public function setIsBatchable($value)
    {
        $this->isBatchable = ($value === 'Y' || $value === true) ? true : false;
    }

    /**
     * @return boolean
     */
    public function getIsBatchable()
    {
        return (bool) $this->isBatchable;
    }

    /**
     * Set check physical flag
     *
     * @param mixed $value
     */
    public function setCheckPhysical($value)
    {
        $this->checkPhysical = ($value === 'Y' || $value === true) ? true : false;
    }

    /**
     * Set check receipt date flag
     *
     * @param mixed $value
     */
    public function setCheckReceiptDate($value)
    {
        $this->checkReceiptDate = ($value === 'Y' || $value === true) ? true : false;
    }

    /**
     * Set is included in history flag
     *
     * @param mixed $value
     */
    public function setIsIncludedInHistory($value)
    {
        $this->isIncludedInHistory = ($value === 'Y' || $value === true) ? true : false;
    }

    /**
     * Set is force to zero allowed flag
     *
     * @param mixed $value
     */
    public function setIsForceToZeroAllowed($value)
    {
        $this->isForceToZeroAllowed = ($value === 'Y' || $value === true) ? true : false;
    }

    /**
     * Set is suppress allowed flag
     *
     * @param mixed $value
     */
    public function setIsSuppressAllowed($value)
    {
        $this->isSuppressAllowed = ($value === 'Y' || $value === true) ? true : false;
    }

    /**
     * Set is exclude allowed flag
     *
     * @param mixed $value
     */
    public function setIsExcludeAllowed($value)
    {
        $this->isExcludeAllowed = ($value === 'Y' || $value === true) ? true : false;
    }

    /**
     * Set inventory adjustment reference code
     *
     * @param mixed $value
     */
    public function setReferenceCode($value)
    {
        $this->referenceCode = trim($value);
    }

    /**
     * Set batch priority
     *
     * @param mixed $value
     */
    public function setBatchPriority($value)
    {
        $this->batchPriority = (int) $value;
    }

    /**
     * Set inventory types array
     *
     * @param array $value
     */
    public function setInventoryTypes(array $value)
    {
        $this->inventoryTypes = (array) $value;
    }

    /**
     * Set special handling array
     *
     * @param array $value
     */
    public function setSpecialHandling(array $value)
    {
        $this->specialHandling = (array) $value;
    }
}
