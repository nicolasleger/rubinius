require File.expand_path('../../../spec_helper', __FILE__)
require File.expand_path('../fixtures/classes', __FILE__)

describe "Enumerable#reject" do
  it "returns an array of the elements for which block is false" do
    EnumerableSpecs::Numerous.new.reject { |i| i > 3 }.should == [2, 3, 1]
    entries = (1..10).to_a
    numerous = EnumerableSpecs::Numerous.new(*entries)
    numerous.reject {|i| i % 2 == 0 }.should == [1,3,5,7,9]
    numerous.reject {|i| true }.should == []
    numerous.reject {|i| false }.should == entries
  end

  it "returns an Enumerator if called without a block" do
    EnumerableSpecs::Numerous.new.reject.should be_an_instance_of(enumerator_class)
  end

  it "gathers whole arrays as elements when each yields multiple" do
    multi = EnumerableSpecs::YieldsMulti.new
    multi.reject {|e| e == [3, 4, 5] }.should == [[1, 2], [6, 7, 8, 9]]
  end

  it "returns the correct size when no block is given" do
    enum = EnumerableSpecs::NumerousWithSize.new(1, 2, 3, 4, 5, 6)
    enum.reject.size.should == 6
  end
end
